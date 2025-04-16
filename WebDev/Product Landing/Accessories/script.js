const stars = document.querySelectorAll(".star");
const ratingValueDisplay = document.getElementById("rating-value");
let ratingValue = 0;

stars.forEach((star) => {
  star.addEventListener("click", function () {
    ratingValue = this.getAttribute("data-value");
    ratingValueDisplay.textContent = `Rating: ${ratingValue}`;

    stars.forEach((s) => s.classList.remove("selected"));

    this.classList.add("selected");
    let nextStar = this.nextElementSibling;
    while (nextStar) {
      nextStar.classList.add("selected");
      nextStar = nextStar.nextElementSibling;
    }
  });
});

document.addEventListener("DOMContentLoaded", function () {
  let selectedRating = 0;

  // Capture the rating when a star is clicked
  document.querySelectorAll(".star").forEach((star) => {
    star.addEventListener("click", function () {
      selectedRating = this.getAttribute("data-value");
      document.getElementById("rating-value").textContent = `Rating: ${selectedRating}`;
    });
  });

  // Review submission
  document.getElementById("submitButton").addEventListener("click", function () {
    const nameInput = document.querySelector(".review-name").value.trim();
    const reviewText = document.getElementById("review-text").value.trim();
    const listOfReviews = document.getElementById("reviews-list");

    if (!nameInput || !reviewText || selectedRating === 0) {
      alert("Please fill in all fields and select a rating.");
      return;
    }

    function displayRating(rating) {
      let stars = '';
      for (let i = 1; i <= rating; i++) {
        stars += `<span class="star selected" data-value="${i}">&#9733;</span>`;
      }
      return stars;
    }

    listOfReviews.innerHTML += `
      ${displayRating(selectedRating)}
      <div class="review">
        <p><strong>${nameInput}</strong></p>
        <p>${reviewText}</p>
      </div>`;

    // Reset the fields after submission
    document.querySelector(".review-name").value = "";
    document.getElementById("review-text").value = "";
    document.getElementById("rating-value").textContent = "Rating: 0";
    document.querySelectorAll('.rating .star.selected').forEach(star => star.classList.remove('selected'));
    selectedRating = 0;
  });
});