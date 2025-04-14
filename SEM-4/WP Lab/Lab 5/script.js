document.addEventListener('DOMContentLoaded', function() {
    const form = document.getElementById('myForm');
    const username = document.getElementById('username');
    const email = document.getElementById('email');
    const password = document.getElementById('password');
    const confirmPassword = document.getElementById('confirm-password');

    form.addEventListener('submit', function(e) {
        let isValid = true;

        // Username validation
        if (username.value.length < 3) {
            showError('username', 'Username must be at least 3 characters long');
            isValid = false;
        } else {
            clearError('username');
        }

        // Email validation
        if (!isValidEmail(email.value)) {
            showError('email', 'Please enter a valid email address');
            isValid = false;
        } else {
            clearError('email');
        }

        // Password validation
        if (password.value.length < 8) {
            showError('password', 'Password must be at least 8 characters long');
            isValid = false;
        } else {
            clearError('password');
        }

        // Confirm password validation
        if (password.value !== confirmPassword.value) {
            showError('confirm-password', 'Passwords do not match');
            isValid = false;
        } else {
            clearError('confirm-password');
        }

        if (!isValid) {
            e.preventDefault();
        }
    });

    function isValidEmail(email) {
        const re = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        return re.test(email);
    }

    function showError(field, message) {
        const errorElement = document.getElementById(`${field}-error`);
        errorElement.textContent = message;
    }

    function clearError(field) {
        const errorElement = document.getElementById(`${field}-error`);
        errorElement.textContent = '';
    }
});