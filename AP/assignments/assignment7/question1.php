<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>String Concatenation</title>
</head>
<body>
    <h1>String Concatenation Methods</h1>
    <form method="post" action="">
        <label for="string1">Enter First String:</label>
        <input type="text" id="string1" name="string1" required>
        <br><br>
        <label for="string2">Enter Second String:</label>
        <input type="text" id="string2" name="string2" required>
        <br><br>
        <button type="submit">Concatenate</button>
    </form>

    <?php
        if ($_SERVER["REQUEST_METHOD"] == "POST" && isset($_POST['string1']) && isset($_POST['string2'])) {
            $string1 = $_POST['string1'];
            $string2 = $_POST['string2'];

            echo "<h2>Results:</h2>";

            $result = $string1 . $string2;
            echo "<h3>Concatenation (Dot Operator): $result</h3>";

            $result_sprintf = sprintf("%s%s", $string1, $string2);
            echo "<h3>Using sprintf(): $result_sprintf</h3>";

            $result_curly = "{$string1}{$string2}";
            echo "<h3>Using Curly Braces: $result_curly</h3>";

            $result_implode = implode("", [$string1, $string2]);
            echo "<h3>Using implode(): $result_implode</h3>";

            $result_join = join("", [$string1, $string2]);
            echo "<h3>Using join(): $result_join</h3>";
        }
    ?>
</body>
</html>
