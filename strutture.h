typedef struct task
{
    int id;
    struct istruzione *prossimaIstruzione;
    int arrival_time;
    int stato;
    struct istr_list *lista_istruzioni;
    int burst;
    float ratio;

}task;

typedef struct istruzione
{
    int type_flag;
    int length;

}istruzione;

typedef struct istr_list{
    istruzione istruzione;
    struct istr_list *next;
}istr_list;

typedef struct task_list{
    task task;
    struct task_list *next;
}task_list;