function fillHeart(heartButton) {
  const heartIcon = heartButton.querySelector("img");
  const isFilled = heartIcon.src.includes("heart-filled.svg");


  if (isFilled) {
    heartIcon.src = "assets/logos/heart.svg"; 
  } else {
    heartIcon.src = "assets/logos/heart-filled.svg"; 
  }
}

function scrollToLeft() {
    var grid = document.querySelector(".grid");
  
    grid.scrollBy({
      left: -450,  
      behavior: 'smooth' 
    });
  
  }
  
  function scrollToRight() {
    var grid = document.querySelector(".grid");
  
    grid.scrollBy({
      left: 450,   
      behavior: 'smooth'  
    });
  
  }


  