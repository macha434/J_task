main()
{
  int fd;
  char buf[10];
  char ent[1]={10};
  fd=open("data",0);
  char ct[1]={fd+'0'};
  read(fd,buf,10);
  write(1,buf,10);
  write(1,ent,1);
  write(1,ct,1);
  close(fd);
}