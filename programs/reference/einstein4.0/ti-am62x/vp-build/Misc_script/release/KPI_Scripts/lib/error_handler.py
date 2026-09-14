import sys

import lib.ce as ce


def visit(exception, **kwargs):
	if not isinstance(exception, Exception):
		raise TypeError

	err = lambda err_msg: print(f'[ERROR] {err_msg}', file=sys.stderr)

	try:
		raise exception
	except ce.NoConfigFileError as filename:
		err(f'Configuration file \'{filename}\' not found!')
	except ce.InvalidStreamError as stream_name:
		err(f'Invalid parameter \'{stream_name}\'.'
			f'Refer config file \'{kwargs["config_file"]}\'')
	except (ce.ConfigFileParamError, KeyError) as parameter:
		err(f'Parameter {parameter} is not '
			f'available in \'{kwargs["config_file"]}\'')
	except ce.HTTPRequestFailError as status:
		err(f'Unable to fetch data from Coverity server!\n'
			f'Failed with http response code {status}!')
	except ce.NoImpactColumnError:
		err(f'Required column \'Impact\' is not in fetched data.')
	except FileNotFoundError as fof:
		err(fof)
	except Exception as e:
		err('Unaddressed exception!')
		print(e, file=sys.stderr)

	try:
		exit(kwargs['exit_code'])
	except KeyError:
		exit(1)

