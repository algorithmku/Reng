process.stdin.resume();
process.stdin.setEncoding('ascii');

var input_stdin = "";
var input_stdin_array = "";
var input_currentline = 0;

process.stdin.on('data', function (data) {
    input_stdin += data;
});

process.stdin.on('end', function () {
    input_stdin_array = input_stdin.split("\n");
    main();    
});

function readLine() {
    return input_stdin_array[input_currentline++];
}

/////////////// ignore above this line ////////////////////

function migratoryBirds(n, ar) {
    // Complete this function
    ar.sort();
    var count =1;
    var max_count =0;
    var value = ar[0];
    var result = 0;
    for( var i = 0; i < n + 1; ++i ){
        if( ar[i] == ar[i+1] ){
            ++count;
        }
        else{
            count = 1;
        }
        if ( max_count < count ) {
            max_count = count;
            result = ar[i];
        }
    }
    return result;
}

function main() {
    var n = parseInt(readLine());
    ar = readLine().split(' ');
    ar = ar.map(Number);
    var result = migratoryBirds(n, ar);
    process.stdout.write("" + result + "\n");

}
