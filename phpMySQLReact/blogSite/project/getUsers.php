<?php
    session_start();
    
    // Connect to the database
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=project", "root", NULL);
    } catch (PDOExecption $e) {
        exit('Database connection failed: ' . $e->getMessage());
    }
    
    // Retrieve the click count for logged in user.
    $stmt = $dbh->prepare("SELECT username FROM users"); // Sets statement for mysql, increments counter when page is viewed
    $stmt->execute() or exit("SELECT failed."); // Executes $stmt
    
    try {
        
        if ($stmt->rowCount() == 0) {
            $response = array('result' => 'failure');
            // User record was deleted after login.
            exit();
        }
        
        $usernames = array();
        
        foreach ($stmt as $row) {
            $usernames[] = $row['username'];
        }
        
        
    } catch (PDOException $e) {
        $response = array('result' => 'error', 'msg' => $e->getMessage());
        print(json_encode($response));
        exit(); 
    }
    
    // Assume that all is good.
    $response = array('result' => 'success', 'usernames' => $usernames);
    print(json_encode($response));

    
    
?>