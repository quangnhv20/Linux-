#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <hiredis/hiredis.h>
int main(int argc, char **argv) {
     redisContext *conn;
     redisReply *reply;

     struct timeval timeout = { 1, 500000 }; // 1.5 seconds
     conn = redisConnectWithTimeout("localhost", 6379, timeout);
     if (conn == NULL || conn->err) {
                if (conn) {
             printf("Connection error: %s\n", conn->errstr);
             redisFree(conn);
                } else {
             printf("Connection error: can't allocate redis context\n");
                }
     exit(1);
     }

     /* Set */
     reply = (redisReply *)redisCommand(conn,"SET %s %s", "welcome", "Hello Redis!");
     printf("SET: %s\n", reply->str);
     freeReplyObject(reply);

     /* Get */
     reply = (redisReply *)redisCommand(conn,"GET welcome");
     printf("GET dump: %s\n", reply->str);
     freeReplyObject(reply);

     /* Disconnects and frees the context */
     redisFree(conn);
     return 0;
}

