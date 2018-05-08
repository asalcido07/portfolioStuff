<?php
    session_start();

    $request = json_decode(file_get_contents("php://input"), true);
    
    // Extract the username and password from the request message.
    $username = $request['username'];
    $password = $request['password'];
    
    if (is_null($username) || is_null($password)) {
        $response = array('result' => 'error', 'msg' => 'Invalid request');
        print(json_encode($response));
        exit(); 
    }
    
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=project", "root", NULL); // Creates PDO
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // ATTR_ERRMODE reports, errors, ERRMODE_EXPECTION throws exceptions
        $stmt = $dbh->prepare("SELECT password, blogtext FROM users WHERE username=:username"); // Sets statement for mysql, increments counter when page is viewed
        $stmt->bindParam(":username", $username);
        $stmt->execute(); // Executes $stmt
        if ($stmt->rowCount() == 0) {
            $response = array('result' => 'failure');
            print(json_encode($response));
            exit();
        }
        $row = $stmt->fetch();
        $actual_password = $row["password"];
        if ($password != $actual_password) {
            $response = array('result' => 'failure');
            print(json_encode($response));
            exit();
        }
    } catch (PDOException $e) {
        $response = array('result' => 'error', 'msg' => $e->getMessage());
        print(json_encode($response));
        exit(); 
    }
    
    $_SESSION["username"] = $username;
    
    $blogtext = $row["blogtext"];
    
    // Assume that all is good.
    $response = array('result' => 'success', 'blogtext' => $blogtext);
    print(json_encode($response));
?>