<?php 
    try {
        $dbh = new PDO("mysql:host=localhost;dbname=track1", "root", NULL); // Creates PDO
        $dbh->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION); // ATTR_ERRMODE reports, errors, ERRMODE_EXPECTION throws exceptions
        $stmt = $dbh->prepare("UPDATE page_views SET counter = counter + 1"); // Sets statement for mysql, increments counter when page is viewed
        $stmt->execute(); // Executes $stmt
        $stmt = $dbh->prepare('SELECT counter FROM page_views'); // Sets statement for mysql, will display value when executed
        $stmt->execute(); // Executes $stmt
        $row = $stmt->fetch(); // Fetches result stores in $row
        $counter = $row["counter"]; // Stores value from the index "counter" or 0 from the $row array
    } catch (PDOException $e) {
        exit($e->getMessage());
    }
?>

<h1>Track 1 Assignment</h1>

<p>
    Page Views: <?php print($counter) ?>
</p>

<p>
Page footer
</p>