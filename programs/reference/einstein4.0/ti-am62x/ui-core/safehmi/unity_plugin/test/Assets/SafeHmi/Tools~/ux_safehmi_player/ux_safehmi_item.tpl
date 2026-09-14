class Item@id@ : public ux_safehmi_item
{
public:
    Item@id@(const int32_t px, const int32_t py, const int32_t pwidth, const int32_t pheight, const bool pvisible, 
	          const uint32_t pcolor, const int32_t pchildcount, const ux_safehmi_item ** const pchildren, const sHMI_ObjType ptype) :ux_safehmi_item(px, py, pwidth, pheight, 
                                                             pvisible, pcolor, pchildcount, pchildren, ptype)
    {
       @constructor@
    }
    @methods@
};

Item@id@ @id@(@x@, @y@, @width@, @height@, @visible@, @color@, @CHILDLIST_IDC_SIZE@, @lc_childlist_id@, sHMI_ObjType::eItem);

