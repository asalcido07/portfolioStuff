<?php 
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=track2", "root", NULL); // Creates PDO
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // ATTR_ERRMODE reports, errors, ERRMODE_EXPECTION throws exceptions
        $stmt = $dbh->prepare("UPDATE page_views SET counter = counter + 1"); // Sets statement for mysql, increments counter when page is viewed
        $stmt->execute(); // Executes $stmt
        $stmt = $dbh->prepare('SELECT counter FROM page_views'); // Sets statement for mysql, will display value when executed
        $stmt->execute(); // Executes $stmt
        $row = $stmt->fetch();
        $counter = $row["counter"];
        /*print('
        <script type="text/javascript"> 
            var jsCounter = "'.$counter.'"
            console.log("Page Views: " + jsCounter);
        </script>');*/
 // Stores value from the index "counter" or 0 from the $row array
    } catch (PDOException $e) {
        exit($e->getMessage());
    }
        $repsonseObject = array(counter => $counter); // Fetches result stores in $row
        $jsonString = json_encode($repsonseObject);
        print($jsonString);
?>

