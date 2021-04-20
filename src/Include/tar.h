#ifndef _TAR_
#define _TAR_

typedef struct
{
	unsigned char *buffer;
	int size,type,offset;
}ELIEGE_TAR;

void ELIEGE_Tar(ELIEGE_TAR *tar,char *pathtar,char *filename,int option,void *buffer,int size);

#define ELIEGE_TAR_DEBUG		0x01
#define ELIEGE_TAR_INFO		0x02
#define ELIEGE_TAR_BUFFER	0x04
#define ELIEGE_TAR_OFFSET	0x08

#endif


