
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

void print_animal();

// for line 86 :Flexible Array Members
struct len_string{
        int length;
        char data[];
};

//Fake OOP : line 126
    //pointer to the struct is the same as a pointer to the first element of the struct
    struct parent{
        int a ,b;
    };
    struct child{
        struct parent parent; // must be first
        int c ,d ;
    };

struct len_string *len_string_from_c_string(char *s);
void print_parent(void *p);
void print_child(struct child *self);


int main(){
    struct passenger{
        char *name;
        int covid_vaccinated;// boolean
    };
    #define MAX_PASSENGERS 8

    struct cabin_manufacture{
        int window_count;
        int o2Level;
    };

    struct spaceShip{
        char *manufacturer;
        struct passenger passenger[MAX_PASSENGERS];
        struct cabin_manufacture ci;
    };

    struct spaceShip s = {
        .manufacturer= "General Products",
        .passenger={
            // Initialize a field at a time
            [0].name = "Gridley, Lewis", 
            [0].covid_vaccinated = 0,

            // Or all at once
            [7] = {.name="Brown, Teela", .covid_vaccinated=1},
        },
        .ci ={
            .window_count = 8,
            .o2Level = 44
        }
    };
    //safely add some shared information between structs in the union.
    printf("%s : %d seats %d%% oxygen",
        s.manufacturer,s.ci.window_count,s.ci.o2Level);
    for(int i = 0; i < MAX_PASSENGERS; i++){
       if(s.passenger[i].name != NULL){
            printf("%s (%svaccinated)\n",
            s.passenger[i].name,s.passenger[i].covid_vaccinated?"":"not ");
       }
    }

    //Anonymous structs

    struct{
        char *name;
        int leg_count,speed;
    }a,b,c; // 3 variables of this struct type

    // example
    a.name = "antelope";
    c.leg_count =4;

    //Self-Referential structs
    struct node{
        int data;
        struct node *next;
    };

    // a hackish linked list setup
    struct node *head;

    head = malloc(sizeof(struct node))  ;
    head->data = 12;
    head->next = malloc(sizeof(struct node));
    head->next->data = 14;
    head->next->next = malloc(sizeof(struct node));
    head->next->next->data = 16;

    //traverse it 
    for(struct node *cur = head; cur != NULL; cur = cur->next){
        printf("%d\n",cur->data);
    }

    // Flexible Array Members
    //Because data is the last field of the struct, if we overflow that field, 
    //it runs out into space that we already allocated! For this reason, 
    //this trick only works if the short array is the last field in the struct.


    struct len_string *hello_ls = len_string_from_c_string("Hello there"); 
    printf("struct hello_ls data: %s\n",hello_ls->data);

    //Padding Bytes
    //C is allowed to add padding bytes within or after a struct as it sees fit. 
    struct foo { 
        int a;
        char b; 
        int c; 
        char d;
    };
    printf("%zu\n", sizeof(int) + sizeof(char) + sizeof(int) + sizeof(char));
    printf("%zu\n", sizeof(struct foo)); //compiler has added 6 bytes of padding

    //offsetof
    printf("offset a %zu\n", offsetof(struct foo, a)); 
    printf("offset b %zu\n", offsetof(struct foo, b)); 
    printf("offset c %zu\n", offsetof(struct foo, c)); 
    printf("offset d %zu\n", offsetof(struct foo, d));

    //fake OOP

    struct child cc = {.parent.a=1, .parent.b=2, .c=3, .d=4};
    print_child(&cc);
    print_parent(&cc);// works here too for parent data.

    //Bit-Fields
    // for lower-level applications that pack bits together into larger spaces.
    // lets say values that were going to be stored in a and b could be stored 
    //in 5 bits, and the values in c, and d could be stored in 3 bits? 
    //That’s only a total 16 bits. 
    //NOTE:Be specific about the signedness when using bit-fields.
    struct foo2{
        //note:the 5-bit fields can only hold values from 0-31 and the 
        //3-bit fields can only hold values from 0-7.
        unsigned int a:5;
        unsigned int b:5;
        unsigned int c:3; 
        unsigned int d:3;
    };
    printf("size of foo2 using bitfield %zu\n", sizeof(struct foo2));
    //NOTE:C will only combine adjacent bit-fields. otherwise no savings

    //Unnamed Bit-Fields: look documentation
    //Zero-Width Unnamed Bit-Fields: look documenation

    //Unions: like structs but the fields overlap in memory
    //The union will be only large enough for the largest field, 
    //and you can only use one field at a time.
    union ufoo {
        int a, b, c, d, e, f; float g, h;
        char i, j, k, l;
    };

    printf("size of ufoo union %zu\n",sizeof(union ufoo)) ;

    //Unions and Type Punning
    //You can non-portably write to one union field and read from another!

    union pi_foo{
        float a;
        short b;
    };

    union pi_foo pi;
    pi.a = 3.14159;
    printf("type running in pi_foo %.6f\n",pi.a);
    //the object representation for the float 3.14159 was the same as the object
    // represen- tation for the short 4048.
    printf("type running in pi_foo %d\n",pi.b);


    //Pointers to unions
    //under the hood, all these values in a union start at the same place in memory
    float *pi_foo_f = (float *)&pi;
    short *pi_foo_s = (short *)&pi;
    pi.b = 22;
    printf("pi.a : %f\n",pi.a);
    printf("*pi_foo_f %f\n",*pi_foo_f);
    printf("pi.b: %d\n",pi.b);
    printf("*pi_foo_s: %d\n",*pi_foo_s);
    // we can also do unions to pointer
    union pi_foo *po_pi = (union pi_foo *)pi_foo_f;
    po_pi->b = 44;
    printf("pi.b: %d\n",pi.b);
    printf("po_pi->b: %d\n",po_pi->b);
    printf("*pi_foo_s: %d\n",*pi_foo_s) ;

    //Common Initial Sequences in Unions
    //it’s valid to access members of that sequence from any of the union members.
    //names does not matter , just need the type to be same.

    // int and float is common intial sequence in following.
    struct a{
        int a ;
        float b;

        char meh;
    };

    struct b{
        int aa;
        float bb;

        long meh;
    };

    union foo_com{
        struct a cia;
        struct b cib;
    };
    // members of the common initial sequences are inter- changeable in code
    //this allows us a way to 
    union foo_com fcm;
    fcm.cia.a = 24;
    printf("fcm.cia.a %d\n",fcm.cia.a);
    printf("fcm.cib.aa %d\n",fcm.cib.aa);
    

    // usecase: safely add some shared information between structs in the union.
    struct common {
        int type; // common initial sequence
    };
    struct antelope {
        int type; // common initial sequence int loudness;
        int loudness;
    };
    struct octopus {
        int type; // common initial sequence
        int sea_creature;
        float intelligence; 
    };

    union animal {
        struct common common; 
        struct antelope antelope; 
        struct octopus octopus;
    };
    #define ANTELOPE 1
    #define OCTOPUS 2
    union animal x = {.antelope.type=ANTELOPE, .antelope.loudness=12};
    switch (x.common.type) {
        case ANTELOPE:
            printf("Antelope: loudness=%d\n", x.antelope.loudness);
            break;
        case OCTOPUS:
            printf("Octopus : sea_creature=%d\n", x.octopus.sea_creature); 
            printf(" intelligence=%f\n", x.octopus.intelligence);
            break;
        default:
            printf("Unknown animal type\n");
    }

    //Unions and Unnamed Structs
    union foo_anon { 
        struct {
            int x, y; 
        } a;
        struct {
            int z, w;
        } b; 
    };
    union foo_anon fanon;
    fanon.a.x = 23;
    printf("fanon.a.x: %d\n",fanon.a.x);
    printf("fanon.b.z: %d\n",fanon.b.z);

    //Passing and Returning structs and unions
    // you can pass by value  or pointer too...
    
} 

struct len_string *len_string_from_c_string(char *s){
    int length = strlen(s);
    struct len_string *ls = malloc(sizeof(*ls)*length);
    ls->length = length;
    memcpy(ls->data,s,length);
    return  ls;
}

void print_parent(void *p){
    struct parent *self = p;
    printf("Parent : %d %d\n",self->a,self->b);
}

void print_child(struct child *self){
    printf("Child: %d %d\n",self->c,self->d);
}
