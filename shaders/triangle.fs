varying vec2 v_texcoords;
uniform sampler2D u_sampler;

// Const for the illumination system

const float ambientStrength = .0f;
const vec4 ambientLight = vec4(1.0f,0.f,0.f,ambientStrength);

void main() {
    vec4 color = texture2D(u_sampler, v_texcoords);

    // Phong material

    // Ambient light component :
    vec4 result = v_color * ambientLight;

    // TODO : Add diffuse light
    // TODO : Add specular light
    // TODO : Add diffuse + ambient + specular to illumination system to create a phong material

    gl_FragColor = color;
}