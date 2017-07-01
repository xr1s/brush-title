URL='http://www.wechall.net/en/challenge/can_you_readme/'

if [ -z $1 ]; then
    echo 'You have to paste cookie as first parameter' 1>&2
    exit 1
fi

COOKIE="${1##WC=}"

curl "${URL}?cmd=Answer&solution=`curl "${URL}gimme.php" --cookie "WC=${COOKIE}" 2> /dev/null | tesseract stdin stdout`" --cookie "WC=${COOKIE}" 2> /dev/null | grep --perl-regex --color "correct|wrong|out of time"
