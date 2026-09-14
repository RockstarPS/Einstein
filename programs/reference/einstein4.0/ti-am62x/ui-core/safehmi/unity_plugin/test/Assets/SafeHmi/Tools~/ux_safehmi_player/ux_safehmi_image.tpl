class Image@id@ : public ux_safehmi_image
{
public:
    Image@id@(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren, @parameters@) :ux_safehmi_image(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren, @baseparam@)
    {
       @constructor@
    }
    @methods@
};

Image@id@ @id@(@x@, @y@, @width@, @height@, @visible@, @color@, @CHILDLIST_IDC_SIZE@, @lc_childlist_id@, @imgptr@ @,num_images@);