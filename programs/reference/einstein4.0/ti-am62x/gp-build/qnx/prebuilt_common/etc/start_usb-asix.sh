echo "starting usb-asix devnp and enabling qconn"

io-pkt-v6-hc -d asix
if_up -p ax0
ifconfig ax0 up
ifconfig ax0 192.168.10.5

echo "starting qconn.."
sleep 5
devc-pty
waitfor /dev/ptyp0 4
waitfor /dev/socket 4
qconn port=8000
inetd &
