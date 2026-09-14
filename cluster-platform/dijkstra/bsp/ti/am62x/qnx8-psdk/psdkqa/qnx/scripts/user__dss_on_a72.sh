echo "user.sh called..."

echo Setting additional environment variables...
export PS1='J7EVM@QNX:$(pwd)# '
export PATH=:/proc/boot:/bin:/sbin:/usr/bin:/usr/sbin:/opt/bin:/ti_fs:/ti_fs/bin:/ti_fs/sbin:/ti_fs/usr/bin:/ti_fs/usr/sbin:/ti_fs/tibin:/ti_fs/vision_apps:/ti_fs/scripts
export LD_LIBRARY_PATH=:/proc/boot:/lib:/usr/lib:/lib/dll:/opt/lib:/ti_fs/lib:/ti_fs/usr/lib:/ti_fs/lib/dll/mmedia:/ti_fs/lib/dll:/ti_fs/tilib:/ti_fs/vision_apps:/ti_fs/usr/lib/graphics/j721e
export GRAPHICS_ROOT=/ti_fs/usr/lib/graphics/j721e
export OMXIL_COMPONENT_PATH=/ti_fs/tilib

echo "Starting tisci-mgr.."
tisci-mgr
waitfor /dev/tisci 2

echo "Starting shmemallocator.."
shmemallocator

echo "Starting tiipc-mgr.."
tiipc-mgr

echo "Starting tiudma-mgr.."
tiudma-mgr

# Starting video encoder resource mgr
vxe_enc

# Starting video decoder resource mgr
vxd_dec

echo "Start screen.."
screen -c /ti_fs/usr/lib/graphics/j721e/graphics.conf
echo "screen started with dss_on_a72 configuration.."
