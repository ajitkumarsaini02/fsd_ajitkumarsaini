function validateForm() {
  const name = document.getElementById("name").value.trim();
  const password = document.getElementById("password").value.trim();

  const nameRegex = /^[A-Za-z ]+$/;

  if (name.length < 6) {
    alert("Name must be at least 6 characters long.");
    return false;
  }

  if (!nameRegex.test(name)) {
    alert("Name should contain alphabets and spaces only.");
    return false;
  }

  if (password.length < 6) {
    alert("Password must be at least 6 characters long.");
    return false;
  }

  alert("Registration Successful!");
  return true;
}
