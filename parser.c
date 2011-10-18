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
	char *test="gggg<a href=\"examenI.pdf\">examenI.pdf</a>                   18-Jul-2006 11:57   95K ggggg ";
/* Compile regular expression */

	reti = regcomp(&regex,"<a[ \t]href=\"[^\"]+\">\([^<>]+\)</a>[ \t]+(0?[1-9]|[12][0-9]|3[01])-[A-Z][a-z]{2}-[0-9]{4}[ \t]+([0-1][0-9]|2[0-3]):[0-5][0-9][ \t]+(-?|[0-9]*)",REG_EXTENDED)
;
        if( reti ){ fprintf(stderr, "Could not compile regex\n"); exit(1); }

/* Execute regular expression */
        reti = regexec(&regex,test, 2,machout, 0);
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
	strncpy(to,test+26,37);
	printf("start=%d end=%d\n",machout[1].rm_so,machout[1].rm_eo);
	printf("\n%s\n",to);
/* Free compiled regular expression if you want to use the regex_t again */
	regfree(&regex);

        return 0;
}
// /r/n/r/n
