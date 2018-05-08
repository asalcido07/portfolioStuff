<?php 

    // If user is not logged in, then do nothing.
    session_start();
    if (!isset($_SESSION['username'])) {
        exit("Not logged in.");
    }
    
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=login", "root", NULL);
    } catch (PDOException $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    $stmt = $dbh->prepare("UPDATE users SET click_count = click_count + 1 WHERE username = :username");
    $stmt->bindParam(':username', $_SESSION['username']) or exit("bind param failed.");
    $stmt->execute() or exit("UPDATE failed.");
    
   
/*   
    $stmt = $dbh->prepare("SELECT click_count FROM users WHERE username= :username");
    $stmt->execute() or exit("SELECT failed.");
    
    $row = $stmt->fetch() or exit("fetch failed.");
    $click_count = $row["click_count"];

    $response = array(click_count => $click_count);
    print(json_encode($response));
*/
?>