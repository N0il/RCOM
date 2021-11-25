#include "../includes/file.h"

int get_file_size(FileInfo* fi, FILE * file){
  fseek(file, 0, SEEK_END);
  fi->size = ftell(file); 
  fseek(file, 0, SEEK_SET); 
  return 0;
}

int read_file(FileInfo* fi, FILE *file){
  fi->data = (unsigned char*) malloc (fi->size);
  fread(fi->data, sizeof(unsigned char), fi->size, file);

  if(fi->size<0){
    return -1;
  }
  return 0;
}

int fillInfo(FileInfo* fi, FILE *file, char *file_name){

  fi->name = file_name;
  
  if(get_file_size(fi, file)<0){ //preenche o file->size
    return -1;
  }

  if(read_file(fi, file)<0){//preenche o file->data
    return -1;
  }
  return 0;
}

unsigned char* dataChunk(unsigned char* data, int start_index, int quantity){
  unsigned char* chunk = malloc(quantity);

  for(int i = 0; i < quantity; i++){
    chunk[i] = data[start_index + i];
  }

  return chunk;

}
