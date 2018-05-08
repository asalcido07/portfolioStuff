<?php
    session_start();
    
    if (!isset($_SESSION['username'])) {
        exit(); 
    }
    
    $username = $_SESSION['username'];
    
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=react", "root", NULL); // Creates PDO
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // ATTR_ERRMODE reports, errors, ERRMODE_EXPECTION throws exceptions
        $stmt = $dbh->prepare("UPDATE users SET click_count = click_count + 1 WHERE username=:username"); // Sets statement for mysql, increments counter when page is viewed
        $stmt->bindParam(":username", $username);
        $stmt->execute(); // Executes $stmt
        $stmt = $dbh->prepare("SELECT click_count FROM users WHERE username=:username");
        $stmt->bindParam(":username", $username);
        $stmt->execute();
        if ($stmt->rowCount() == 0) {
            $response = array('error' => 'Something unknown has happened.');
            print(json_encode($response));
            exit();
        }
        $row = $stmt->fetch();
    } catch (PDOException $e) {
        $response = array('result' => 'error', 'msg' => $e->getMessage());
        print(json_encode($response));
        exit(); 
    }
    
    $clickCount = $row["click_count"];
    
    // Assume that all is good.
    $response = array('result' => 'success', 'clickCount' => $clickCount);
    print(json_encode($response));
?>