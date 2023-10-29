function validate() {
  var password1 = document.getElementById("password1").value;
  var password2 = document.getElementById("password2").value;

  if (password1.length < 8) {
    alert(
      "The first password is too short. It must be at least eight characters."
    );
  } else if (password2.length < 8) {
    alert(
      "The second password is too short. It must be at least eight characters."
    );
  } else if (password1 !== password2) {
    alert("Passwords do not match. Please enter the same password twice.");
  } else {
    alert("Passwords matched!");
  }
}
