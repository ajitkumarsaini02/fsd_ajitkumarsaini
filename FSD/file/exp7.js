function validateForm() {
  const name = document.getElementById("name").value.trim();
  const password = document.getElementById("password").value.trim();
  const email = document.querySelector('input[placeholder="Enter your E-mail ID"]').value.trim();
  const phone = document.querySelector('input[placeholder="Enter Phone Number"]').value.trim();

  const nameRegex = /^[A-Za-z ]+$/;
  if (name.length < 6 || !nameRegex.test(name)) {
    alert("❌ Name must contain only alphabets and be at least 6 characters long.");
    return false;
  }

  if (password.length < 6) {
    alert("❌ Password must be at least 6 characters long.");
    return false;
  }

  const emailRegex = /^[a-zA-Z0-9._%+-]+@[a-zA-Z0-9.-]+\.[A-Za-z]{2,}$/;
  if (!emailRegex.test(email)) {
    alert("❌ Please enter a valid E-mail ID (e.g. name@domain.com).");
    return false;
  }

  const phoneRegex = /^[0-9]{10}$/;
  if (!phoneRegex.test(phone)) {
    alert("❌ Phone number must contain exactly 10 digits.");
    return false;
  }

  alert("✅ Registration Successful!");
  return true;
  
}
