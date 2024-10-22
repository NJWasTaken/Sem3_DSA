//cs2.h

#define MAXSTRING 50

typedef struct myfile{
    char *filename;
    struct myfile *next;
} MYFILE;

typedef struct m_directory{
    char* dirName;
    struct m_directory *subdir;
    struct m_directory *next;
    MYFILE *files;
    struct m_directory *parent;
} M_DIR;

typedef struct FileSystem{
    M_DIR *root;
} M_FILESYSTEM;

enum CmdVal {CD_CMD,MKDIR_CMD,LS_CMD,TOUCH_CMD,EXIT_CMD,INVALID_CMD};

typedef struct cmdval{
    char *cmd;
    enum CmdVal val;
} CMDVAL;

int ValidateCmd(char *);
M_FILESYSTEM *Allocate_fs(char *);
M_DIR *Allocate_dir(char *,M_DIR *);
int MakeDir(M_DIR *,char *);
M_DIR *ChangeDir(M_FILESYSTEM *,char *);
void ShowFiles (M_FILESYSTEM *);
int CreateFile(M_DIR *, char *);
void AddSibling(M_DIR *,M_DIR *);
void free_mem(M_FILESYSTEM *);

