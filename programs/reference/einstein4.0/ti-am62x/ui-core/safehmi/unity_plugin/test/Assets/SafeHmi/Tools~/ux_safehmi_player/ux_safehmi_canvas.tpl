class Canvas@id@ : public ux_safehmi_canvas
{
public:
    Canvas@id@(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible,
			  const uint32_t pcolor, const uint32_t pchildcount, const ux_safehmi_item ** const pchildren) :ux_safehmi_canvas(px, py, pwidth, pheight, 
                                                                      pvisible, pcolor, pchildcount, pchildren)
    {
       @memallocs@
       @constructor@
    }
    @methods@
};

Canvas@id@ @id@(@x@, @y@, @width@, @height@, @visible@, @color@, @CHILDLIST_IDC_SIZE@, @lc_childlist_id@);
