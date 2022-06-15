varying vec2 v_texcoords;
uniform sampler2D u_sampler;

// Const for the illumination system

const float ambientStrength = .0f;
const vec4 ambientLight = vec4(1.0f,0.f,0.f,ambientStrength);

// Diffuse component
const vec3 diffuse_pos = vec3(0.0f,0.0f,0.0f);
varying vec3 vert_normal;

void main() {
    vec4 color = texture2D(u_sampler, v_texcoords);

    // Phong material

    // TODO : Add diffuse light
    vec3 normalize_vert = normalize(vert_normal);
    float d = dot(normalize_vert,diffuse_pos);
    float m = max(d,1);

    // TODO : Add specular light
    // TODO : Add diffuse + ambient + specular to illumination system to create a phong material
    vec4 result = v_color * ambientLight;

    gl_FragColor = color;
}