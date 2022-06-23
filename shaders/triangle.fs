varying vec2 v_texcoords;
uniform sampler2D u_sampler;

// Const for the illumination system

const float light_strength = .10;
const vec4 light_color = vec4(1.0, 1.0, 1.0, 1.);

// Diffuse component
const vec3 diffuse_pos = vec3(0.0, 0.0, 10.0);
varying vec3 vert_normal;

void main() {

    vec4 color = texture2D(u_sampler, v_texcoords);

    // Ambient light

    vec4 ambient = light_strength * light_color;

    // TODO : Add diffuse light
    vec4 normalize_vert = normalize(vec4(vert_normal, 1.));
    vec4 light_dir = normalize(vec4(diffuse_pos, 1.) - vec4(v_texcoords, .0, .0));
    float tmp = dot(normalize_vert, light_dir);

    vec4 diffuse = max(tmp, 0.0) * light_color;

    // TODO : Add specular light
    // TODO : Add diffuse + ambient + specular to illumination system to create a phong material

    gl_FragColor = (ambient + diffuse) * color;
}