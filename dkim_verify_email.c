#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
int main(){
	int i;
  for(i=1; i<=10 ; i++)
  {
      struct timeval timeVar1;
      struct timeval timeVar2;
      struct timeval timeVar3;
      struct timeval timeVar4;
      struct timeval timeVar5;
      struct timeval timeVar6;
      struct timeval timeVar7;
      struct timeval timeVar8;

      char command2048SHA1[200];
      sprintf(command2048SHA1, "openssl dgst -sha1 -verify rsapublickey2048.pem -signature ./Output/2048SHA1/cipher%d.txt.sig msg%d.txt" , i,i);
      gettimeofday(&timeVar1, NULL);
      system(command2048SHA1);
      gettimeofday(&timeVar2, NULL);
      printf("2048sha1  %ld\n", (timeVar2.tv_usec-timeVar1.tv_usec)/1000 );

      char command1024SHA1[200];
      sprintf(command1024SHA1, "openssl dgst -sha1 -verify rsapublickey1024.pem -signature ./Output/1024SHA1/cipher%d.txt.sig msg%d.txt" , i,i);
      gettimeofday(&timeVar3, NULL);
      system(command1024SHA1);
      gettimeofday(&timeVar4, NULL);
      printf("1024sha1  %ld\n", (timeVar4.tv_usec-timeVar3.tv_usec)/1000 );

      char command2048SHA256[200];
      sprintf(command2048SHA256,"openssl dgst -sha256 -verify rsapublickey2048.pem -signature ./Output/2048SHA256/cipher%d.txt.sig msg%d.txt" ,i ,i);
      gettimeofday(&timeVar5, NULL);
      system(command2048SHA256);
      gettimeofday(&timeVar6, NULL);
      printf("2048sha256  %ld\n", (timeVar6.tv_usec-timeVar5.tv_usec)/1000 );

      char command1024SHA256[200];
      sprintf(command1024SHA256 , "openssl dgst -sha256 -verify rsapublickey1024.pem -signature ./Output/1024SHA256/cipher%d.txt.sig msg%d.txt" , i, i);
      gettimeofday(&timeVar7, NULL);
      system(command1024SHA256);
      gettimeofday(&timeVar8, NULL);
      printf("1024sha256  %ld\n", (timeVar8.tv_usec-timeVar7.tv_usec)/1000 );
  }      
}
