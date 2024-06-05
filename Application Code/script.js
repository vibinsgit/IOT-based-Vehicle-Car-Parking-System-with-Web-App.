document.addEventListener('DOMContentLoaded', function() {
    let firstCircle = document.getElementById("first-circle");
    let secondCircle = document.getElementById("second-circle");
    let thirdCircle = document.getElementById("third-circle");
    let v10, v11, v12;

    function data() {
        const blynk = fetch("https://blr1.blynk.cloud/external/api/get?token=6yB1HSjCMn7QIbwQ6BzcYtnCgNY8Y7YN&v10&v11&v12");
        //  https://blr1.blynk.cloud/external/api/get?token=6yB1HSjCMn7QIbwQ6BzcYtnCgNY8Y7YN&v10&v11&v12 ---> "Enter your blynk token."
        const allData = blynk.then(response => response.json());

        const result = allData.then(apiData => {
            v10 = apiData.v10;
            v11 = apiData.v11;
            v12 = apiData.v12;

            console.log(v10);
            console.log(v11);
            console.log(v12);

            if (v10 > 0) {
                firstCircle.style.backgroundColor = "red";
                firstCircle.style.borderColor = "red";
                // firstCircle.style.backgroundImage = "url('car.png')";

            }
            if (v11 > 0) {
                secondCircle.style.backgroundColor = "red";
                secondCircle.style.borderColor = "red";
                // secondCircle.style.backgroundImage = "url('car.png')";


            }
            if (v12 > 0) {
                thirdCircle.style.backgroundColor = "red";
                thirdCircle.style.borderColor = "red";
                // thirdCircle.style.backgroundImage = "url('car.png')";


            }
        });
    }

    data();

    setInterval(function() {
        location.reload();
    }, 5000);
});
