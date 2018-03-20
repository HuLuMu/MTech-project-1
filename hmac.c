#include <openssl/hmac.h>
#include <stdio.h>
#include <openssl/err.h>
#include <string.h>
#include<openssl/evp.h>
// #include<iostream>

// using namespace std;

void print_hex(unsigned char *bs, unsigned int n)
{
 int i;
 for (i = 0; i < n; i++)
  printf("%02x", bs[i]);
}

int PRF(){
  char data[]="Hello World";
  char key[]="012345678";
  unsigned char hash[EVP_MAX_MD_SIZE];
  unsigned int hashlen;
  HMAC(EVP_sha1(),key,sizeof(key),data,strlen(data),hash,&hashlen);
  print_hex(hash,hashlen);
  printf("\n");
  // cout<<endl;
  return 0;
}
