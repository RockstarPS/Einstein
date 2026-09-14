#define DRM_EVENT_CONTEXT_VERSION 2
typedef struct _drmEventContext {
    int version;
    void (*vblank_handler)(int fd, unsigned int sequence, unsigned int tv_sec, unsigned int tv_usec, void *user_data);
    void (*page_flip_handler)(int fd, unsigned int sequence, unsigned int tv_sec, unsigned int tv_usec, void *user_data);
} drmEventContext;

int drmSetMaster(int fd);

int drmHandleEvent(int fd, drmEventContext *evctx);
int drmDropMaster(int fd);

