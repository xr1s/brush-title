<?php
function asvsmysql_login($username, $password)
{
        $username = addslashes($username);
        $password = md5($password);
        
        if (false === ($db = gdo_db_instance('localhost', ADDSLASH_USERNAME, ADDSLASH_PASSWORD, ADDSLASH_DATABASE, GWF_DB_TYPE, 'GBK'))) {
                return htmlDisplayError('Can`t connect to database.');
        }
 
        $db->setLogging(false);
        $db->setEMailOnError(false);
        
        $query = "SELECT username FROM users WHERE username='$username' AND password='$password'";
        
        if (false === ($result = $db->queryFirst($query))) {
                return htmlDisplayError('Wrong username/password.');
        }
        
        if ($result['username'] !== 'Admin') {
                return htmlDisplayError('You are logged in, but not as Admin.');
        }
        
        return htmlDisplayMessage('You are logged in. congrats!');
}
?>
