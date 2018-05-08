<?php

    session_start();
    
    if(!isset($_SESSION['username'])){
        $response = array('result' => 'notLoggedIn');
        print(json_encode($response));
        exit();
    }
    
    $username = $_SESSION['username'];
    
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=project", 'root', null);
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $stmt = $dbh->prepare('SELECT blogtext FROM users WHERE username=:username');
        $stmt->bindParam(':username',$username);
        $stmt->execute();
        if($stmt->rowCount() == 0){
            $response = array('result' => 'failure');
            exit();
        }
        $row = $stmt->fetch();
        $blogText = $row['blogtext'];
        
    } 
    catch (PDOException $e) {
        $response = array('result' => 'error','msg' => $e->getMessage());
        print(json_encode($response));
        exit();
    }

    $response = array('result' => 'LoggedIn' ,'blogText' => $blogText);
    //console.log($clickCount);
    print(json_encode($response));
?>