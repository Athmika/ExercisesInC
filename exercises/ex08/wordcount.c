#include <glib.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void printHash (gpointer key,
     gpointer value, gpointer user_data)
     {
       printf(user_data, key,(int *) value);
     }

  int main()
  {

      char* word[1000];
      GArray *garray;

      gsize length;
      gchar *content, *filename = "test.txt";
      if (!g_file_get_contents (filename, &content, &length, NULL))
{
          printf("error\n");
      }

      garray = g_array_new (FALSE, FALSE, sizeof (char));

      /*int word_index = 0;
      int num_elements = 0;
      FILE * fp;
      gchar * line = NULL;
      size_t len = 0;

      fp = fopen("test.txt", "r");
      if (fp == NULL)
          exit(EXIT_FAILURE);


      while ((getline(&line, &len, fp)) != -1) {
             char *token = strtok(line, " ");
             while (token != NULL)
             {
               word[word_index] = ;
               token = strtok(NULL, " ");
               word_index++;
               num_elements++;
             }
      }

      printf("%d\n",num_elements);
      fclose(fp);
      if (line) free(line);
      GHashTable *table;
      int i;*/

      gchar **strings = g_strsplit(content," ",-1);
      gchar **ptr;
      GHashTable *table = g_hash_table_new (g_str_hash, g_str_equal);


      for (ptr = strings; *ptr; ptr++)
      {
         printf("%s\n", *ptr);
         if (g_hash_table_lookup(table,*ptr))
         {
           printf("found\n");
           g_hash_table_insert (table,*ptr, g_hash_table_lookup(table,*ptr)+1);
         }
         else{
            g_hash_table_insert (table,*ptr,GINT_TO_POINTER (1));
         }
      }
      g_hash_table_foreach(table,printHash,"%s: %d\n");
       return 0;
}
