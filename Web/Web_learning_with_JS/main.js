

// Basic scripts to work with concole and document 
// document.write("Джава скрипт говорит првиет");
// console.log("Джава скрипт говорит привет");
// console.info("Джава скрипт говорит привет");
// console.error("Джава скрипт говорит есть ошибка");
// console.warn("Джава скрипт говорит првиет");


// Vars
// const string = "Hello";
// var num = 10;
// num += 400;
// console.log("Переменная: " + num);


// Mathematics 
// const num_1 = 3;
// var num_2 = 10;
// console.log("Cуммирование: " + (num_1 + num_2));
// console.log("Вычетание: " + (num_1 - num_2));
// console.log("Умножение: " + (num_1 * num_2));
// console.log("Деление: " + (num_1 / num_2));
// console.log("Остаток от деления: " + (num_2 % num_1));
// console.log("Возведение в квадрат: " + (num_2 ** num_1));
// num_2++;

// var str_1 = Number("12");
// var str_2 = Number("14");
// console.log(str_1 + str_2);


// Math - object
// console.log("Math: " + Math.PI);
// console.log("Math: " + Math.min(2,3,6,6,8,5,2));
// console.log("Math: " + Math.max(2,3,6,6,8,5,2));


//Arrays
// var array = new Array(12,24,32,4232,5432,6,7,8,9);
// var arr = [1,2,3,4,5,6,7,8,9];
// console.log(array);
// console.log(arr[4]);


//Matrix
// var matrix = [[1,2,3],[1,2,3],[1,2,3]]
// matrix[1][2] = 90;
// console.log(matrix);


//Всплывающие окна
// alert("Ема прикол");

// confirm("Я тупой?");
// var user_choice = confirm("Я тупой?")
// if( user_choice )
//     alert("ТУДА");

// prompt("Сколько вам лет?", 18)


//Function
// var word = "Hello";
// function info(word) {
//     console.log(word + "!");
// }
// info(word);

// function message(){
//     alert("Пососи");
// }

// var counter = 0;

// function message(element){
//     counter++;
//     element.innerHTML = "Нажатий: " + counter;
//     element.style.cssText = "border-radius: 10px; border: 1px, black, solid; background-color: white; color: black; font-size: 30px;"
// }


// var tag = document.getElementById('id');
// tag.style.cssText = "color: yellow";
// tag.id = "sosi";
// console.log(tag.id);
// tag.style.background = "red";

// var spans = document.getElementsByTagName('span');
// for(var i = 0; i < spans.length; ++i) {
//     console.log(spans[i].innerHTML);
// }


function checkForm(event) {
    event.preventDefault(); // Останавливает стандартное поведение формы
    var name = event.target.name.value;
    var pass = event.target.pass.value;
    var repass = event.target.repass.value;
    var state = event.target.state.value;

    if (pass === repass){
        confirm("Вы правда хотите подтвердить действие?");
        window.location = "https://www.youtube.com/watch?v=1nzH6WCEonQ&list=PLDyJYA6aTY1kJIwbYHzGOuvSMNTfqksmk&index=13"
        return false;
    }
    else
        alert("Пароли не совпадают!");

    console.log(name + " - " + state + " - " + pass + " - " + repass + ";");
}
