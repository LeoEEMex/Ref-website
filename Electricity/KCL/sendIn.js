<script>
function sendDataToC() {
    // 1. Grab the values from the HTML boxes
    let I_1 = document.getElementById('I_1').value;
    let I_2 = document.getElementById('I_2').value;
    let I_3 = document.getElementById('I_3').value;


    // 2. Pass those exact values into your C function
    // (Using Number() ensures they are treated as math numbers, not text)
    Module._KCL(Number(userAge), Number(userHeight));
}
</script>