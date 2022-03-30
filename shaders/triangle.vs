attribute vec2 a_position;
attribute vec3 a_color;

varying vec4 v_color;

uniform float u_time;

void main() {
    vec2 offset = vec2(sin(u_time), 0.0);
    vec2 pos = a_position + offset;

    gl_Position = vec4(pos, 0.0, 1.0);
    v_color = vec4(a_color, 1.0);
}