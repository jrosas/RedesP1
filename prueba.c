#include <stdio.h>
#include <time.h>
 
/*
 * El resultado debe ser algo así como
 * Fri 2008-08-22 15:21:59 WAST
 */
 
int main(void)
{
    time_t     now;
    time_t   t1;
    time_t   t2;
    struct tm *ts;
    struct tm ts2;
    struct tm *ts3;
    char       buf[80];
    char       buf2[80];
    char *hora;
    double tiempo;
    double tiempo2;
    
    hora="1990-18-10 10:22:33";
    /* Obtener la hora actual */
    now = time(0);
 
    /* Formatear e imprimir el tiempo, "ddd yyyy-mm-dd hh:mm:ss zzz" */
    ts = localtime(&now);
    printf ("tiempo maquina\n");
    strftime(buf, sizeof(buf), "%Y-%d-%m %H:%M:%S \n ", ts);
    printf("%s\n", buf);
        //printf("%s\n", hora);
    
    
    
    printf ("tiempo viejo\n");
    strptime(hora, "%Y-%d-%m %H:%M:%S", &ts2);
    strftime(buf2, sizeof(buf2), "%Y-%d-%m %H:%M:%S\n ", &ts2);
    //printf("Entrando a los mktime1");
    printf("%s\n", buf2);
    //printf("Entrando a los mktime2");
    
    //printf("Entrando a los mktime3");
    t1 = mktime(ts);
    ts3=&ts2;
    //printf("Entrando a los mktime2");
    t2  = mktime(ts3);
    
    tiempo = difftime(t1, t2);
    tiempo2 = difftime(t2, t1);
    printf ("timepo 1: %f\n", tiempo);
    printf ("timepo 2: %f\n", tiempo2);
    
 
    return 0;

  
    
    
    
    
    
    
}



/*
 * #include <stdio.h>
#include <time.h>
 
/*
 * El resultado debe ser algo así como
 * Fri 2008-08-22 15:21:59 WAST
 
 
int main(void)
{
    time_t     now;
    time_t   t1;
    time_t   t2;
    struct tm *ts;
    struct tm ts2;
    char       buf[80];
    char       buf2[80];
    char *hora;
    double tiempo;
    double tiempo2;
    
    hora="1990-18-10 10:22:33";
    /* Obtener la hora actual 
    now = time(0);
 
    /* Formatear e imprimir el tiempo, "ddd yyyy-mm-dd hh:mm:ss zzz" 
    ts = localtime(&now);
    printf ("tiempo maquina\n");
    strftime(buf, sizeof(buf), "%Y-%d-%m %H:%M:%S \n ", ts);
    printf("%s\n", buf);
        //printf("%s\n", hora);
    
    
    
    printf ("tiempo viejo\n");
    strptime(hora, "%Y-%d-%m %H:%M:%S", &ts2);
    strftime(buf2, sizeof(buf2), "%Y-%d-%m %H:%M:%S\n ", &ts2);
    
    printf("%s\n", buf2);
    
    
    t1 = mktime(ts);
    t2  = mktime(&ts2);
    
    tiempo = difftime(t1, t2);
    tiempo2 = difftime(t2, t1);
    printf ("timepo 1: %f\n", tiempo);
    printf ("timepo 2: %f\n", tiempo2);
    
 
    return 0;

  
    
    
    
    
    
    
}
 * 
 */ 