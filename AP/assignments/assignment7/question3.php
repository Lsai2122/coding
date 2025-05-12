<?php
    $method = $_SERVER["REQUEST_METHOD"];
    $tax = 0;
    $netSalary = 0;

    if ($method == "POST") {
        $name = trim($_POST["name"]);
        $salary = trim($_POST["salary"]);
        $country = $_POST["country"];

        // Name validation: should not contain numbers
        if (!preg_match("/^[a-zA-Z ]+$/", $name)) {
            echo "<h2 style='color: red;'>Error: Name should not contain numbers.</h2>";
        }
        // Salary validation: should be a positive number
        elseif (!is_numeric($salary) || $salary <= 0) {
            echo "<h2 style='color: red;'>Error: Salary must be a positive number.</h2>";
        }
        // Country validation
        elseif (empty($country)) {
            echo "<h2 style='color: red;'>Error: Please select a country.</h2>";
        } 
        else {
            $salary = (float)$salary;

            // Calculate tax based on salary
            if ($salary < 500000) {
                $tax = 0;
            } elseif ($salary <= 1000000) {
                $tax = 0.10 * $salary;
            } elseif ($salary <= 2000000) {
                $tax = 0.20 * $salary;
            } else {
                $tax = 0.30 * $salary;
            }

            $netSalary = $salary - $tax;

            // Display results
            echo "<h2>Results:</h2>";
            echo "<p><strong>Name:</strong> " . htmlspecialchars($name) . "</p>";
            echo "<p><strong>Country:</strong> " . htmlspecialchars($country) . "</p>";
            echo "<p><strong>Gross Salary:</strong> ₹" . number_format($salary, 2) . "</p>";
            echo "<p><strong>Tax Deducted:</strong> ₹" . number_format($tax, 2) . "</p>";
            echo "<p><strong>Net Salary:</strong> ₹" . number_format($netSalary, 2) . "</p>";
            echo "<p><strong>Method Used:</strong> " . $method . "</p>";
        }
    }
?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Tax Calculator</title>
</head>
<body>
    <h1>Tax Calculation Form</h1>
    <form method="post">
        <label for="name">Name:</label>
        <input type="text" id="name" name="name" required>
        <br><br>

        <label for="salary">Salary:</label>
        <input type="number" id="salary" name="salary" step="any" required>
        <br><br>

        <label for="country">Select Country:</label>
        <select id="country" name="country" required>
            <option value="">--Select Country--</option>
            <option value="India">India</option>
            <option value="USA">USA</option>
            <option value="UK">UK</option>
            <option value="Canada">Canada</option>
        </select>
        <br><br>

        <button type="submit">Calculate Tax</button>
    </form>
</body>
</html>
