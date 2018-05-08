<?php
    session_start();

    if (!isset($_SESSION['username'])) {
        // User is not logged in
        $response = array('result' => 'notLoggedIn');
        print(json_encode($response));
        exit(); 
    }
    
    $username = $_SESSION['username'];
    
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=react", "root", NULL); // Creates PDO
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // ATTR_ERRMODE reports, errors, ERRMODE_EXPECTION throws exceptions
        $stmt = $dbh->prepare("SELECT click_count FROM users WHERE username=:username"); // Sets statement for mysql, increments counter when page is viewed
        $stmt->bindParam(":username", $username);
        $stmt->execute(); // Executes $stmt
        if ($stmt->rowCount() == 0) {
            $response = array('result' => 'failure');
            // User record was deleted after login.
            exit();
        }
        $row = $stmt->fetch();
        $clickCount = $row["click_count"];
    } catch (PDOException $e) {
        $response = array('result' => 'error', 'msg' => $e->getMessage());
        print(json_encode($response));
        exit(); 
    }
    
    // Assume that all is good.
    $response = array('result' => 'loggedIn', 'clickCount' => $clickCount);
    print(json_encode($response));

?>