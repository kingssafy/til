////const gulp = require('gulp');
//const babel = require('gulp-babel');
//// Gulp dependencies go here
//gulp.task('default', function(done) {
//    // Node source
//    gulp.src("es6/**/*.js")
//        .pipe(babel())
//        .pipe(gulp.dest("dist"));
//    // browser source
//    gulp.src("public/es6/**.*.js")
//        .pipe(babel())
//        .pipe(gulp.dest("public/dist"));
//    done();
//});

const gulp = require('gulp');
const babel = require('gulp-babel');
const eslint = require('gulp-eslint');
// Gulp dependencies go here
gulp.task('default', function(done) {
  // Run ESLint
  gulp.src(["es6/**/*.js", "public/es6/**/*.js"])
    .pipe(eslint())
    .pipe(eslint.format());
  // Node source
  gulp.src("es6/**/*.js")
    .pipe(babel())
    .pipe(gulp.dest("dist"));
  // browser source
  gulp.src("public/es6/**.*.js")
    .pipe(babel())
    .pipe(gulp.dest("public/dist"));
  done();
});
