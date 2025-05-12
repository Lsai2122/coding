<?php
    $result = '';
    $error = '';

    if ($_SERVER["REQUEST_METHOD"] == "POST") {
        $num1 = isset($_POST['num1']) ? (float)$_POST['num1'] : null;
        $num2 = isset($_POST['num2']) ? (float)$_POST['num2'] : null;
        $operator = $_POST['operator'] ?? null;

        if ($num1 === null || $num2 === null || $operator === null) {
            $error = "Error: Please enter all fields.";
        } else {
            switch ($operator) {
                case '+': $result = $num1 + $num2; break;
                case '-': $result = $num1 - $num2; break;
                case '*': $result = $num1 * $num2; break;
                case '/': 
                    $result = ($num2 == 0) ? ($error = 'Error: Division by zero.') : ($num1 / $num2);
                    break;
                case '%': 
                    $result = ($num2 == 0) ? ($error = 'Error: Division by zero.') : ($num1 % $num2);
                    break;
                default: $error = 'Error: Invalid operator.';
            }
        }
    }
?>
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simple Calculator</title>
</head>
<body>
    <h1>Simple Calculator</h1>
    <form method="post">
        <label for="num1">Number 1:</label>
        <input type="number" step="any" name="num1" id="num1" required>
        <br><br>
        <label for="operator">Operator:</label>
        <select name="operator" id="operator" required>
            <option value="+">+</option>
            <option value="-">-</option>
            <option value="*">*</option>
            <option value="/">/</option>
            <option value="%">%</option>
        </select>
        <br><br>
        <label for="num2">Number 2:</label>
        <input type="number" step="any" name="num2" id="num2" required>
        <br><br>
        <button type="submit">Calculate</button>
    </form>

    <?php if ($result !== '' && $error === ''): ?>
        <h2>Result: <?php echo htmlspecialchars($result); ?></h2>
    <?php elseif ($error !== ''): ?>
        <h2 style="color: red;"><?php echo htmlspecialchars($error); ?></h2>
    <?php endif; ?>
</body>
</html>
