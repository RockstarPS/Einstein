import json
import jsonschema
import jinja2
import argparse

def max_string_property_length(arr, property_name):
    max_length = len(property_name)
    for obj in arr:
        if property_name in obj and isinstance(obj[property_name], str):
            length = len(obj[property_name])
            if length > max_length:
                max_length = length
    return max_length

parser = argparse.ArgumentParser(description="Example script to process files.")
parser.add_argument("input_file", help="Input file address")
parser.add_argument("output_file", help="Output file path")

args = parser.parse_args()

input_file_address = args.input_file
output_file_path = args.output_file

with open(input_file_address,"r") as json_file:
    target = json.load(json_file)

with open('schema.json',"r") as json_schema:
    schema = json.load(json_schema)


try:
    # Validate the JSON data against the schema
    jsonschema.validate(instance=target, schema=schema)
    print("Validation successful. The JSON data is valid.")

    template_loader = jinja2.FileSystemLoader(searchpath="./")
    template_env = jinja2.Environment(loader=template_loader)
    template_env.filters['max_string_property_length'] = max_string_property_length
    template = template_env.get_template('tmpl.j2')

    out_code = template.render(target)

    with open(output_file_path,'w') as out:
        out.write(out_code)
except jsonschema.exceptions.ValidationError as e:
    try:
        print(f"\n\nValidation failed\nThe entry \n{target[e.path[0]][e.path[1]]}\n doesnot comply with specified schema for the field {e.path[2]} {e.schema}\n\n")
    except:
        print(f"\n\nValidation fialed: {e}\n\n")
    exit(1)
