struct gbm_device;
struct gbm_bo;
struct gbm_surface;

union gbm_bo_handle {
    void *ptr;
    int32_t s32;
    uint32_t u32;
};


#define GBM_BO_FORMAT_XRGB8888   __gbm_fourcc_code('X', 'R', '2', '4')

#define fourcc_code(a, b, c, d) \
    ((uint32_t)(a) | ((uint32_t)(b) << 8) | \
    ((uint32_t)(c) << 16) | ((uint32_t)(d) << 24))

#define GBM_BO_FORMAT_XRGB8888 fourcc_code('X', 'R', '2', '4')

#define GBM_BO_USE_RENDERING (1 << 0)
#define GBM_FORMAT_XRGB8888      GBM_BO_FORMAT_XRGB8888

struct gbm_device *gbm_create_device(int fd);

struct gbm_surface *gbm_surface_create(struct gbm_device *gbm, uint32_t width,uint32_t height,uint32_t format,uint32_t flags);

void gbm_surface_release_buffer(struct gbm_surface *surface, struct gbm_bo *bo);
struct gbm_bo *gbm_surface_lock_front_buffer(struct gbm_surface *surface);
uint32_t gbm_bo_get_stride(struct gbm_bo *bo);
union gbm_bo_handle gbm_bo_get_handle(struct gbm_bo *bo);
void gbm_surface_destroy(struct gbm_surface *surface);
void gbm_device_destroy(struct gbm_device *gbm);


