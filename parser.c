#include <sys/types.h>
#include <regex.h>
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

int main(int argc, char *argv[]){
        regex_t regex;
        int reti;
        char msgbuf[100];
	regmatch_t machout[4];
	char *test="gggg<a href=\"examenI.pdf\">examenI.pdf</a>                   18-Jul-2006 11:57   95K ggggggggg<a href=\"examenI.pdf\">examenI.pdf</a>                   18-Jul-2006 11:57   95K ggggg ";
/* Compile regular expression */

	reti = regcomp(&regex,"<a[ \t]href=\"[^\"]+\">\([^<>]+)</a>[ \t]+\([0-3]?[0-9]-[A-Z][a-z]{2}-[0-9]{4}[ \t]+[0-2][0-9]:[0-5][0-9])[ \t]+\(-?|[0-9]*)",REG_EXTENDED)
;
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

/* Execute regular expression */
        reti = regexec(&regex,test, 4,machout, 0);
        if( !reti ){
                puts("Match");
        }
        else if( reti == REG_NOMATCH ){
                puts("No match");
        }
        else{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                exit(1);
        
	}printf("\n%s\n","sasd");
	char to[100];
	//to=strndup(test+26,41);
	//strncpy(to,test+26,37);
	printf("start=%d end=%d\n",machout[0].rm_so,machout[0].rm_eo);
	printf("start=%d end=%d\n",machout[1].rm_so,machout[1].rm_eo);
	printf("start=%d end=%d\n",machout[2].rm_so,machout[2].rm_eo);
	printf("start=%d end=%d\n",machout[3].rm_so,machout[3].rm_eo);
	printf("%s\n",test+4);
	printf("%s\n",test+26);
	printf("%s\n",test+60);
	printf("%s\n",test+80);
/* Free compiled regular expression if you want to use the regex_t again */

	reti = regexec(&regex,test+82, 4,machout, 0);
        if( !reti ){
                puts("Match");
        }
        else if( reti == REG_NOMATCH ){
                puts("No match");
        }
        else{
                regerror(reti, &regex, msgbuf, sizeof(msgbuf));
                fprintf(stderr, "Regex match failed: %s\n", msgbuf);
                exit(1);
        
	}
printf("\n%s\n","sasd");
	regfree(&regex);

	//        return 0;

	printf("start=%d end=%d\n",machout[0].rm_so,machout[0].rm_eo);
	printf("start=%d end=%d\n",machout[1].rm_so,machout[1].rm_eo);
	printf("start=%d end=%d\n",machout[2].rm_so,machout[2].rm_eo);
	printf("start=%d end=%d\n",machout[3].rm_so,machout[3].rm_eo);
	printf("%s\n",test+82+11);
	printf("%s\n",test+82+33);
	printf("%s\n",test+82+67);
	printf("%s\n",test+82+87); 
}
// /r/n/r/n
