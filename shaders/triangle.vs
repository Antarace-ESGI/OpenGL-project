attribute vec3 a_position;
attribute vec2 a_texcoords;

varying vec2 v_texcoords;

uniform float u_time;
uniform mat4 u_rotation;
uniform mat4 u_projection;

void main() {
    gl_Position =  u_projection * u_rotation * vec4(a_position, 1.0);
    v_texcoords = a_texcoords;
}