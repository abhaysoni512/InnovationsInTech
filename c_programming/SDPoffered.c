    #include <stdio.h>
    #include <string.h>

    int main(){
        char sdp_offered[] = 
            "v=0\n"
            "c=IN IP4 192.168.1.10\n"
            "m=audio 5004 RTP/AVP 0\n";
        
            char current_line[100];
            char response[200]="v=0\n"; // we are start building response

            // we will use strtok to spilt into response
            char *token = strtok(sdp_offered,"\n");
            while (token!=NULL)
            {
                // copy the content present on token to current_line
                strncpy(current_line,token,sizeof(current_line)-1);
                current_line[sizeof(current_line)-1] = '\0';

                if(strncmp(current_line,"c=",2) == 0 || strncmp(current_line,"m=",2)==0){
                strncat(response, current_line, sizeof(response) - strlen(response) - 1);
                    strncat(response, "\n", sizeof(response) - strlen(response) - 1);
                }

                token = strtok(NULL,"\n");
            }

            printf("Response : %s\n",response);
            


        return 0;
    }