echo "user.sh called..."

echo Setting additional environment variables...
export PS1='J784S4-EVM@QNX:$(pwd)# '
export PATH=:/proc/boot:/bin:/sbin:/usr/bin:/usr/sbin:/opt/bin:/ti_fs:/ti_fs/bin:/ti_fs/sbin:/ti_fs/usr/bin:/ti_fs/usr/sbin:/ti_fs/tibin:/ti_fs/scripts
export LD_LIBRARY_PATH=:/proc/boot:/lib:/usr/lib:/lib/dll:/opt/lib:/ti_fs/lib:/ti_fs/usr/lib:/ti_fs/lib/dll/mmedia:/ti_fs/lib/dll:/ti_fs/tilib
export GRAPHICS_ROOT=/ti_fs/usr/lib/graphics/j784s4
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

echo "Starting ti-vpu-codec-mgr"
ti-vpu-codec-mgr

echo "Start screen.."
screen -c /ti_fs/usr/lib/graphics/j784s4/graphics-dummy.conf
echo "screen started with dss_on_r5 configuration.."
