<?php
/**
 * Get the database instance
 * @return GDO_Database
 */
function gbook_db()
{
        static $gbdb = true;
        if ($gbdb === true)
        {
                $gbdb = gdo_db_instance('localhost', CHALL_GBOOK_USER, CHALL_GBOOK_PASS, CHALL_GBOOK_DB);
                $gbdb->setLogging(false); // Disable annoying logs. 
                $gbdb->setEMailOnError(false); // Disable annoying emails.
        }
        return $gbdb;
}
 
/**
 * Create the 2 tables for the challenge.
 */
function gbook_createTables()
{
        $db = gbook_db();
        
        // user table can not get populated, but an admin account exists
        $query =
                "CREATE TABLE IF NOT EXISTS gbook_user ( ".
                "gbu_id        INT(11)     UNSIGNED PRIMARY KEY, ". # Guestbook userid
                "gbu_name      VARCHAR(63) CHARACTER SET ASCII COLLATE ascii_general_ci, ". # Guestbook username
                "gbu_password  VARCHAR(255) CHARACTER SET ASCII COLLATE ascii_bin ) "; # Guestbook password <-- You need the password for username Admin
        $db->queryWrite($query);
        
        // the guestbook messages table
        $query =
                "CREATE TABLE IF NOT EXISTS gbook_book ( ".
                "gbb_sessid   CHAR(16)     CHARACTER SET ASCII COLLATE ascii_bin, ". # Every wechall user gets his own guestbook, so you maybe can`t spoil it that easily.
                "gbb_uid      INT(11)      UNSIGNED, ". # GB userid (currently unused)
                "gbb_time     INT(11)      UNSIGNED, ". # Timestamp
                "gbb_ip       VARCHAR(32)  CHARACTER SET ASCII COLLATE ascii_bin, ".       # IP
                "gbb_msg      TEXT         CHARACTER SET utf8  COLLATE utf8_general_ci, ". # Message
                "INDEX(gbb_sessid) )";
        $db->queryWrite($query);
}
 
/**
 * Cleanup very old messages.
 */
function gbook_cleanup()
{
        $db = gbook_db();
        $cut = time() - GWF_TIME::ONE_DAY * 2;
        $query = "DELETE FROM gbook_book WHERE gbb_time<$cut";
        return $db->queryWrite($query);
}
 
/**
 * Generate a unique ID, so guests can also play this challenge. Every player gets his own guestbook.
 * This part is unimportant for the challenge!
 */
function gbook_playerID($reset=false)
{
        return GWF_Session::getSessID(); # new session == new game
}
 
/**
 * Get IP
 */
function gbook_getIP()
{
        if (isset($_SERVER['HTTP_X_FORWARDED_FOR'])) {
                return $_SERVER['HTTP_X_FORWARDED_FOR'];
        }
        elseif (isset($_SERVER['HTTP_VIA'])) { 
                return $_SERVER['HTTP_VIA'];
        }
        else {
                return $_SERVER['REMOTE_ADDR'];
        }
}
 
 
/**
 * Insert a message for current player.
 * @param int $userid
 * @param string $message
 */
function gbook_insertMessage($userid, $message)
{
        $db = gbook_db();
        
        $message = trim($message);
        $len = strlen($message);
        
        if ($len <= 3) {
                echo GWF_HTML::error('The Guestbook', 'Your message is too short.');
                return false;
        }
        
        if ($len > 256) {
                echo GWF_HTML::error('The Guestbook', 'Your message is too long.');
                return false;
        }
 
        # insert the entry      
        $playerid = gbook_playerID(true); // Current Player
        $userid = 0; # guestbook has no login yet.
        $time = time();
        $ip = gbook_getIP();
        $message = mysql_real_escape_string($message);
        $query = "INSERT INTO gbook_book VALUES('$playerid', $userid, $time, '$ip', '$message')";
        if (false === $db->queryWrite($query)) {
                echo GWF_HTML::err('ERR_DATABASE', array(__FILE__, __LINE__));
                return false;
        }
        
        echo GWF_HTML::message('The Guestbook', 'Your entry has been added.');
        return true;
}
 
/**
 * Manually clear the guestbook for current player.
 */
function gbook_clear()
{
        $db = gbook_db();
        $playerid = gbook_playerID();
        $query = "DELETE FROM gbook_book WHERE gbb_sessid='$playerid'";
        return $db->queryWrite($query);
}
 
/**
 * Get Form to sign guestbook.
 */
function gbook_form()
{
        return sprintf('<form action="index.php" method="post"><textarea name="message" rows="12" cols="40"></textarea><input type="submit" name="sign" value="Sign Guestbook" /><input type="submit" name="clear" value="Clear Guestbook" /></form>');
}
 
/**
 * Display guestbook of current player.
 */
function gbook_display()
{
        $db = gbook_db();
        
        $playerid = gbook_playerID();
        
        $query = "SELECT * FROM gbook_book WHERE gbb_sessid='$playerid'";
        if (false === ($result = $db->queryAll($query))) {
                return GWF_HTML::err('ERR_DATABASE', array(__FILE__, __LINE__));
        }
        
        echo '<h3>Your Guestbook</h3>'.PHP_EOL;
        
        echo GWF_Table::start();
        foreach ($result as $row)
        {
                $rs = GWF_Table::rowStart();
                $re = GWF_Table::rowEnd();
                $username = GWF_HTML::lang('guest');
                echo $rs;
                echo sprintf('<td>%s - %s - %s</td>', GWF_Time::displayTimestamp($row['gbb_time']), $username, $row['gbb_ip']).PHP_EOL;
                echo $re;
                echo $rs;
                echo sprintf('<td>%s</td>', GWF_HTML::display($row['gbb_msg'])).PHP_EOL;
                echo $re;
        }
        echo GWF_Table::end();
}
?>

